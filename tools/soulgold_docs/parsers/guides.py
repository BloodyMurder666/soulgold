"""Author-friendly Markdown guide discovery for the static documentation site."""

from __future__ import annotations

import re
from pathlib import Path

from ..models import GuideRow
from ..paths import GUIDES_DIR, SRC_DIR


FRONT_MATTER_BOUNDARY = "---"


def _front_matter(text: str) -> tuple[dict[str, str], str]:
    lines = text.splitlines()
    if not lines or lines[0].strip() != FRONT_MATTER_BOUNDARY:
        return {}, text.strip()

    metadata: dict[str, str] = {}
    end = next(
        (index for index, line in enumerate(lines[1:], start=1) if line.strip() == FRONT_MATTER_BOUNDARY),
        None,
    )
    if end is None:
        return {}, text.strip()

    for line in lines[1:end]:
        key, separator, value = line.partition(":")
        if separator:
            metadata[key.strip().lower()] = value.strip().strip('"\'')
    return metadata, "\n".join(lines[end + 1:]).strip()


def _title_from_content(content: str, fallback: str) -> tuple[str, str]:
    lines = content.splitlines()
    for index, line in enumerate(lines):
        match = re.fullmatch(r"#\s+(.+?)\s*", line)
        if not match:
            continue
        title = match.group(1).strip()
        del lines[index]
        return title, "\n".join(lines).strip()
    return fallback, content


def _plain_summary(content: str) -> str:
    for block in re.split(r"\n\s*\n", content):
        line = " ".join(part.strip() for part in block.splitlines()).strip()
        if not line or line.startswith(("#", "!", "```", "- ", "* ", "> ")):
            continue
        line = re.sub(r"!?\[([^]]+)]\([^)]+\)", r"\1", line)
        line = re.sub(r"[*_`~]", "", line)
        return line[:220]
    return ""


def _slug(path: Path) -> str:
    return re.sub(r"[^a-z0-9]+", "-", path.stem.lower()).strip("-")


def parse_guides() -> list[GuideRow]:
    if not GUIDES_DIR.exists():
        return []

    guides: list[GuideRow] = []
    for path in sorted(GUIDES_DIR.rglob("*.md")):
        if path.name.lower() == "readme.md" or path.name.startswith("_"):
            continue

        metadata, content = _front_matter(path.read_text(encoding="utf-8"))
        fallback_title = path.stem.replace("-", " ").replace("_", " ").title()
        content_title, content = _title_from_content(content, fallback_title)
        title = metadata.get("title") or content_title
        try:
            order = int(metadata.get("order", "1000"))
        except ValueError:
            order = 1000

        guides.append({
            "slug": metadata.get("slug") or _slug(path),
            "title": title,
            "summary": metadata.get("summary") or _plain_summary(content),
            "category": metadata.get("category") or "Guide",
            "order": order,
            "source": path.relative_to(SRC_DIR).as_posix(),
            "content": content,
        })

    return sorted(guides, key=lambda guide: (guide["order"], guide["title"].casefold()))

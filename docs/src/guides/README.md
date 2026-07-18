# Writing player guides

Create one Markdown file per guide in this directory. The Guides page discovers
them automatically when `tools/soulgold_docs/build_docs.py` runs.

Start a guide with this optional metadata block:

```markdown
---
title: Finding Lugia
summary: Where to begin the quest and how to reach Lugia.
category: Legendaries
order: 20
---
```

Write the rest with normal Markdown headings, paragraphs, numbered or bulleted
lists, links, block quotes, inline code, and fenced code blocks. A level-one
heading can be used instead of `title`; it is used as the guide title rather
than repeated in the expanded article.

To attach a picture, put it in `images/` and reference it relative to this
directory:

```markdown
![The entrance to the hidden cave](images/hidden-cave.png)
```

Link to another published guide with its relative Markdown filename. The site
turns it into that guide's shareable URL:

```markdown
[Read the legendary prerequisites](legendary-prerequisites.md)
```

Guide slugs, local links, and attached files are validated during the docs
build. A missing picture, duplicate slug, or link to an unpublished Markdown
file fails the build instead of publishing a broken guide.

Files named `README.md` and files whose names begin with `_` are authoring aids
and are not published. Copy `_template.md` when starting a guide.

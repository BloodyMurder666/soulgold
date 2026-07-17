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

Files named `README.md` and files whose names begin with `_` are authoring aids
and are not published. Copy `_template.md` when starting a guide.

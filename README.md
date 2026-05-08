Map scrolling branch
# HAS DEPENDENCY ON COMFY ANIMS BY HUDERLEM https://github.com/huderlem/pokeemerald/tree/comfy_anims

Adds one page horizontal scrolling to region and flymap using a single region map.

How to use:

1) grab this commit by doing the following (I don't recommend pulling since there's a lot of unnecessary stuff in my project):
    > git remote add rahtak https://github.com/Eemeliri/soulgold
    > git fetch rahtak map-scrolling
    > git cherry-pick <map scrolling commit hash>
    
1) point the definition of REGION_MAP_SECOND_PAGE_LAYOUT to your second region maps sRegionMapSections_X layout. (By default points to expansions Sevii123 layout)
2) Do the following edits to porymap region map settings:
    - Add region map with following settings:
    ![Point the map files to your existing region, but have the offsets start full map width later, and use the layout of your second region.](image.png)
    ![now you can edit the second page seperately](image-1.png)


Credits:
- [Huderlem: Comfy Anims](https://github.com/huderlem/pokeemerald/tree/comfy_anims)
- [MatheoVignaud: The idea for how it was done in old Pokeemerald](https://github.com/MatheoVignaud/pokeemerald/tree/scrolling-worldmap)
# BMP-CLI-Editor

This is a C program that implements a BMP picture command line editor.

This editor can be used for overlapping images, drawing lines, creating rectangular and triangular shapes and filling them with color.

I have added to the repo a folder with bmp images and one with example commands for this interface that can be used to test the automatic
implementation using test_script.py. You can run all the proposed tests or one by one in the desired order.

Below are the commands that the editor receives in the terminal:

**edit [path]** - to open a BMP photo and start editing it

**save [path]** - to save the edited photo

**insert [path] y x** - to insert another photo over the current one

**set draw_color R G B** - to set another color for drawing

**set line_width x** - to set another line width

**draw line y1 x1 y2 x2** - to draw a line between 2 points specified by their coordinates

**draw rectangle y1 x1 width height** - to draw a rectangle of specified size at starting point (y1, x1)

**draw triangle y1 x1 y2 x2 y3 x3** - to draw a traingle between (y1, x1), (y2, x2) and (y3, x3)

**fill y x** - to flood-fill with color an area bounded around a point; 
all adjacent points that have the same initial color as the given point are colored in the desired color

**quit** - to close the editor

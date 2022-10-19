build:
	gcc main.c save.c edit.c insert.c draw.c set.c shapes.c fill.c utils.c -o bmp_editor -Wall
run:
	./bmp_editor
clean:
	rm -f bmp_editor


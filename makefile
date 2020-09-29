all:
	m4 -I src -I content index.m4.html | unix2dos > index.html

clean:
	rm index.html
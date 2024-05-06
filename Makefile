all: phcc

phcc:
	mkdir -p autogen
	meson setup buildDir
	cd buildDir && meson compile

check:
	mkdir -p autogen
	meson setup buildDir
	cd buildDir && meson compile && meson test

clean:
	rm -rf buildDir autogen
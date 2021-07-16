#!/bin/bash

arg="$1"

function get_keyboard(){
	echo "$arg" | cut -d ':' -f 1
}

function get_keymap(){
	echo "$arg" | cut -d ':' -f 2
}

if [ ! -f qmk_firmware ]; then
	git clone https://github.com/qmk/qmk_firmware.git
else
	cd qmk_firmware
	git pull
	cd -
fi

cp -r $(get_keyboard)/$(get_keymap) qmk_firmware/keyboards/$(get_keyboard)/keymaps 

cd qmk_firmware && make $arg

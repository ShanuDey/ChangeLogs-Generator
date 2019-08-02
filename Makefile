.SILENT:all
all:
	clear
	echo "*************************************************************"
	echo "*   _____             _                  _____ ______ _   _ *"
	echo "*  / ____|           | |                / ____|  ____| \ | |*"
	echo "* | |     _ __   __ _| |     ___   __ _| |  __| |__  |  \| |*"
	echo "* | |    | '_ \ / _\` | |    / _ \ / _\` | | |_ |  __| | . \` |*"
	echo "* | |____| | | | (_| | |___| (_) | (_| | |__| | |____| |\  |*"
	echo "*  \_____|_| |_|\__, |______\___/ \__, |\_____|______|_| \_|*"
	echo "*                __/ |             __/ |                    *"
	echo "*               |___/             |___/                     *"
	echo "* Created by : Shanu Dey                                    *"
	echo "*************************************************************"
	gcc changeLogMod.c -o changelog_generator
	./changelog_generator raw.txt outputLog.txt
	rm -rf raw.txt
	rm -rf changelog_generator
	
.SILENT:clean
clean:
	rm -rfv raw.txt
	rm -rfv changelog_generator
	rm -rfv outputLog.txt
	echo " #### Cleaning succesfull #### \n"

.SILENT:raw
raw:
	git --git-dir ../.git log --pretty=oneline --abbrev-commit -n 20 > raw.txt
	head --lines=10 raw.txt
	
.SILENT:build
build:
	gcc changeLogMod.c -o changelog_generator
#/bin/bash

for x in $(ls)
do
	if [[ $x != *.cpp ]] && [[ $x != *.sh ]] && [[ $x != *.md ]]
	then
		rm  $x
	fi
done	;

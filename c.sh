#/bin/bash

for x in $(ls)
do
	if [[ $x != *.cpp ]] && [[ $x != *.sh ]]
	then
		rm  $x
	fi
done	;

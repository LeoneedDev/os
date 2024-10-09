#! /bin/csh

foreach f ([A-Z]*)

	echo "$f" | tr A-Z a-z

	mv -i "$f" "`echo '$f' | tr A-Z a-z`"

end

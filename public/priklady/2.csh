#! /bin/csh

foreach u (steinmul lesko paulen)
	who | grep -w $u
end

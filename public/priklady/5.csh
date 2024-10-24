#! /bin/csh

unset debug

while ($#argv > 0)
	switch ("$argv[1]")
		case -d:
			set debug
			breaksw
		case -h:
			echo "Help: ..."
			exit 0
		case -*:
			echo "Neznamy prepinac $argv[1]"
			exit 1
		default:
			breaksw; break
	endsw
	shift
end

if ($?debug) echo "Dalsie argumenty: $argv"

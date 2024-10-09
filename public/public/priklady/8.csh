#! /bin/csh

ls -l

echo ""

foreach v (`ls -l | head -3`)
	echo "$v"
end

echo ""

foreach v ("`ls -l | head -3`")
	echo "$v"
end

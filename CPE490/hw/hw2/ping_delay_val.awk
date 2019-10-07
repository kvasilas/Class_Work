BEGIN {
	data[3]
}

{
	if($1 == 64)
		split($(NF-1), data, "=")
		print data[2]
} 

END {
}

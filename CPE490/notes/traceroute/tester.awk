BEGIN{
    
}

{

}

END{
    print
    #print $8
    delay = $10
    split(delay, data, "=")
    print data[1]
}

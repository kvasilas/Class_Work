BEGIN{
    
}

{

}

END{
    delay = $10
    split(delay, data, "=")
    print data[1]
}

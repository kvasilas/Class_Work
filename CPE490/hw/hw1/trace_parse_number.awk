BEGIN{
    
}

{
    delay = $8
    split(delay, data, "=")
    if ($1 == 64)
        print data[2]
    
}

END{
    
}

// Class on omnet

simple node {
    gates:
        inout port[]; // type name
}


network Network{
    types: 
    
    parmeters:
        int count;
    
    submodules:
        node[count] : Node{
            gates: 
                port[2];
        }
    
    connections:
        node1,port++ <--> C <--> node6.port++ 
        node2.port++ <--> {delay 10ms;} <--> node3.port++
        for i = 0..count-2{
            node[i].port[1]<--> node[i+1].port[0];
        }
}


%x = [0 0 0 0 0 0; 0 0 0 1 1 1; 0 0 1 1 1 1; 0 1 1 1 1 1; 0 0 1 1 1 1; 0 0 0 1 1 1];
x = [0 0 0 1 1 1; 0 0 1 1 1 1; 0 1 1 1 1 1; 0 0 1 1 1 1; 0 0 0 1 1 1];
g1= [ 1 0; 0 -1];
g2= [ 0 1; -1 0];
y1 = conv2(x,g1);
y2 = conv2(x,g2);
%returns the 2d convolution in the scripting section
%assumes starting point of 0,0

__kernel void HelloWorld(__global char* data)
{
data[0] = 'H';
data[1] = 'i';
data[2] = ' ';
data[3] = '!';
data[4] = '\n';

}
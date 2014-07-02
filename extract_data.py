import sys

int i=0;
file = open(sys.argv[1], 'r')
for line in file.readlines():
    data_list = line.split()
    for index in range(6,14):
	if index < len(data_list):
	    i++;
            sys.stdout.write(data_list[index])
	    if data_list[index] == "CD" :
		break
        else: 
	    break
    print("")
file.close()

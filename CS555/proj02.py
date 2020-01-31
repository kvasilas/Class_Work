# Kirk Vasilas
# CS555WS 
# Project 02
# Python3

# test_line = ged.readline()
# print(test_line)
# test_line = test_line.strip('\n')
# test_line = test_line.split(" ")
# lvl_num = test_line.pop(0)
# tag = test_line.pop(0)
# args = " ".join(test_line)

#print(lvl_num, tag,args, sep='\n')

def parse_line(line):
    #may need to add id before tags for some of the zeros thats cool
    zero_tags = ["HEAD", "TRLR", "NOTE", "FAM", "INDI"]
    two_tags  = ["WWW"]
    two_tags  = [""]
    validation = ""
    line = line.strip('\n')
    line = line.split(" ")
    lvl_num = line.pop(0)
    if(lvl_num == "0"):
        if(line[0] not in zero_tags): # <id> <tag>
            person_id = line.pop(0)
            tag = line.pop(0)
            args = " ".join(line)
        else:
            tag = line.pop(0)
            args = " ".join(line)
    elif(lvl_num == "1"):
        tag = line.pop(0)
        args = " ".join(line)
    elif(lvl_num == "2"):
        tag = line.pop(0)
        args = " ".join(line)
    else:
        #not valid numbers go to here
        pass
    ans = lvl_num + "|" + tag + "|" + validation + "|" + args
    return(ans)
    



if __name__ == "__main__":
    path = r'\Users\USER\Documents\coding\Class_Work\CS555\proj02_test.ged'
    ged = open(path, 'r')
    lines = ged.readlines()
    i = 0
    for line in lines:
        i += 1
        answer = parse_line(line.strip())
        #print("Line{}: {}".format(i, line.strip()))
        print(answer)
    ged.close()

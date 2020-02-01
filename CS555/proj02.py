# Kirk Vasilas
# CS555WS 
# Project 02
# Python3


def parse_line(line):
    zero_tags = ["HEAD", "TRLR", "NOTE", "FAM", "INDI"]
    one_tags  = ["NAME", "SEX", "BIRT", "DEAT", "FAMC", "MARR", "HUSB", "WIFE", "CHIL", "DIV"]
    two_tags  = ["WWW", "DATE"]
    validation = ""
    line = line.strip('\n')
    line = line.split(" ")
    lvl_num = line.pop(0)
    if(lvl_num == "0"):
        if(line[0] not in zero_tags): # <id> <tag>
            args = line.pop(0)
            tag = line.pop(0)
        else:
            tag = line.pop(0)
            args = " ".join(line)
        if(tag not in zero_tags):
                validation = "N"
        else:
            validation = "Y"
    elif(lvl_num == "1"):
        tag = line.pop(0)
        args = " ".join(line)
        if(tag not in one_tags):
            validation = "N"
        else:
            validation = "Y"
    elif(lvl_num == "2"):
        tag = line.pop(0)
        args = " ".join(line)
        if(tag not in two_tags):
            validation = "N"
        else:
            validation = "Y"
    else:
        tag = line.pop(0)
        args = " ".join(line)
        validation = "N"
    ans = lvl_num + "|" + tag + "|" + validation + "|" + args
    return(ans)
    



if __name__ == "__main__":
    #path = r'\Users\USER\Documents\coding\Class_Work\CS555\proj02_test.ged' #my windows pc sample
    path = r'\Users\USER\Documents\coding\Class_Work\CS555\proj01.ged'
    #path = r'/home/kcv/Class_Work/CS555/proj02_test.ged' #linux laptop
    ged = open(path, 'r')
    lines = ged.readlines()
    i = 0
    for line in lines:
        i += 1
        answer = parse_line(line.strip())
        #print("Line{}: {}".format(i, line.strip()))
        print(line.strip(), answer, sep='\n')
    ged.close()

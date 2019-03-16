import sys,os
if __name__ == "__main__":
        data=["GdLS","LS"]
        for i in range(0,len(data)):
		os.system("rm -f Script/*err* Script/*out*")
		os.system("chmod 744 "+"Script/"+data[i]+".csh")
		os.system("hep_sub -g dyw "+"Script/"+data[i]+".csh")

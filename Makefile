
########

clean:clean_pro

########


vvv:
	-rm *.csh.err*  *.csh.out*

clean_pro:
	-rm pro
pro:clean_pro
	g++ -o pro pro.cc Event.C EventDict.C -O `root-config --libs` -I. -I/dybfs/users/jixp/software/root/include -L/dybfs/users/jixp/software/root/lib


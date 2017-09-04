import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
from glob import glob
fig1=plt.figure()
fnames = glob('../Result/randomz_valueaftereachstep*.dat')
arrays = [np.loadtxt(f) for f in fnames]
global num_episodes
print len(arrays)
for i in range(len(arrays)):
	arrays[i][arrays[i] == float("inf")] = 0

print np.shape(arrays)[0]
finalmax_diff=[]
for num_iter in np.arange(0,np.shape(arrays)[0]):
	a=arrays[num_iter];

	#a[a == float("inf")] = 0
	b=np.loadtxt("../Result/z_iteration.dat");
	b= b.ravel();
	b[b == float("inf")] = 0
	num_states = np.shape(a)[1]
	num_episodes = np.shape(a)[0]
	max_diff= [] 
	for counter in np.arange(0, num_episodes):
	    diff_list = []
	    for counter2 in np.arange(0, num_states):
	        
	        diff = abs(a[counter][counter2] - b[counter2])
	        diff_list.append(diff)
	    max_diff.append(max(diff_list)/max(b))
	finalmax_diff.append(max_diff);



x=np.arange(0,num_episodes)

y= np.mean(finalmax_diff,axis=0)
z= np.std(finalmax_diff,axis = 0)
print x,y,z
plt.errorbar(x[0::100], y[0::100], z[0::100], linestyle='None', marker='^')
plt.plot(y,label = "Random Z")
fnames = glob('../Result/greedyz_zvalueaftereachsteps*.dat')
arrays = [np.loadtxt(f) for f in fnames]

print len(arrays)
for i in range(len(arrays)):
	arrays[i][arrays[i] == float("inf")] = 0

print np.shape(arrays)[0]
finalmax_diff=[]
for num_iter in np.arange(0,np.shape(arrays)[0]):
	a=arrays[num_iter];

	#a[a == float("inf")] = 0
	b=np.loadtxt("../Result/z_iteration.dat");
	b= b.ravel();
	b[b == float("inf")] = 0
	num_states = np.shape(a)[1]
	num_episodes = np.shape(a)[0]
	max_diff= [] 
	for counter in np.arange(0, num_episodes):
	    diff_list = []
	    for counter2 in np.arange(0, num_states):
	        
	        diff = abs(a[counter][counter2] - b[counter2])
	        diff_list.append(diff)
	    max_diff.append(max(diff_list)/max(b))
	finalmax_diff.append(max_diff);



x=np.arange(0,num_episodes)

y= np.mean(finalmax_diff,axis=0)
z= np.std(finalmax_diff,axis = 0)
print x,y,z

plt.errorbar(x[0::150], y[0::150], z[0::150], linestyle='None', marker='^')

plt.plot(y,label = "Greedy Z")


fnames = glob('../Result/randomq_valueafterstep*.dat')
arrays = [np.loadtxt(f) for f in fnames]

print len(arrays)
for i in range(len(arrays)):
	arrays[i][arrays[i] == float("inf")] = 0

print np.shape(arrays)[0]
finalmax_diff=[]
for num_iter in np.arange(0,np.shape(arrays)[0]):
	a=arrays[num_iter];

	#a[a == float("inf")] = 0
	b=np.loadtxt("../Result/v_iteration.dat");
	b= b.ravel();
	b[b == float("inf")] = 0
	num_states = np.shape(a)[1]
	num_episodes = np.shape(a)[0]
	max_diff= [] 
	for counter in np.arange(0, num_episodes):
	    diff_list = []
	    for counter2 in np.arange(0, num_states):
	        
	        diff = abs(a[counter][counter2] - b[counter2])
	        diff_list.append(diff)
	    max_diff.append(max(diff_list)/max(b))
	finalmax_diff.append(max_diff);



x=np.arange(0,num_episodes)

y= np.mean(finalmax_diff,axis=0)
z= np.std(finalmax_diff,axis = 0)
print x,y,z

plt.errorbar(x[0::130], y[0::130], z[0::130], linestyle='None', marker='^')

plt.plot(y,label = "Random Q")


fnames = glob('../Result/greedyq_valueafterstep*.dat')
arrays = [np.loadtxt(f) for f in fnames]

print len(arrays)
for i in range(len(arrays)):
	arrays[i][arrays[i] == float("inf")] = 0

print np.shape(arrays)[0]
finalmax_diff=[]
for num_iter in np.arange(0,np.shape(arrays)[0]):
	a=arrays[num_iter];

	#a[a == float("inf")] = 0
	b=np.loadtxt("../Result/v_iteration.dat");
	b= b.ravel();
	b[b == float("inf")] = 0
	num_states = np.shape(a)[1]
	num_episodes = np.shape(a)[0]
	max_diff= [] 
	for counter in np.arange(0, num_episodes):
	    diff_list = []
	    for counter2 in np.arange(0, num_states):
	        
	        diff = abs(a[counter][counter2] - b[counter2])
	        diff_list.append(diff)
	    max_diff.append(max(diff_list)/max(b))
	finalmax_diff.append(max_diff);



x=np.arange(0,num_episodes)

y= np.mean(finalmax_diff,axis=0)
z= np.std(finalmax_diff,axis = 0)
print x,y,z

plt.errorbar(x[0::110], y[0::110], z[0::110], linestyle='None', marker='^')

plt.plot(y,label = "Greedy Q")



plt.legend(bbox_to_anchor=(0., 1.02, 1., .1002), loc=3,
           ncol=2, mode="expand", borderaxespad=0.)
plt.show()
"""plt.plot(max_diff,label='Random Z')



plt.show()
fig2.savefig('../Result/Check_iter_approxerror.png')
"""
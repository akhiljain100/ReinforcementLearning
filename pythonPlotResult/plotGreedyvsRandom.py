import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
from glob import glob

fnames = glob('../Result/randomz_valueaftereachstep*.txt')
arrays = [np.loadtxt(f) for f in fnames]
print len(arrays)
for i in range(len(arrays)):
	arrays[i][arrays[i] == float("inf")] = 0

b=np.loadtxt("../Result/z_iteration.txt");
b= b.ravel();
b[b == float("inf")] = 0
final_diff = []
num_states = np.shape(arrays[0])[1]
num_steps = np.shape(arrays[0])[0]
print num_states,num_steps
avg_diff = []
for i in np.arange(0, num_steps):
	diff_list_eachiteration = []
	for j in range(len(arrays)):
		diff_list = []
		for counter2 in np.arange(0, num_states):
			diff = abs(arrays[j][i][counter2] - b[counter2])
			diff_list.append(diff)
		
        diff_list_eachiteration.append(diff_list)
	print diff_list_eachiteration
	avg_diff.append(np.mean(diff_list, axis= 0)/max(b))

fig2 = plt.figure()
plt.plot(avg_diff,label='Random')

fnames = glob('../Result/greedyz_zvalueaftereachsteps*.txt')
arrays = [np.loadtxt(f) for f in fnames]
print len(arrays)
for i in range(len(arrays)):
	arrays[i][arrays[i] == float("inf")] = 0

b=np.loadtxt("../Result/z_iteration.txt");
b= b.ravel();
b[b == float("inf")] = 0
final_diff = []
num_states = np.shape(arrays[0])[1]
num_steps = np.shape(arrays[0])[0]
print num_states,num_steps
avg_diff = []
for i in np.arange(0, num_steps):
	diff_list_eachiteration = []
	for j in range(len(arrays)):
		diff_list = []
		for counter2 in np.arange(0, num_states):
			diff = abs(arrays[j][i][counter2] - b[counter2])
			diff_list.append(diff)
		
        diff_list_eachiteration.append(diff_list)
	#print diff_list_eachiteration
	avg_diff.append(np.mean(diff_list, axis= 0)/max(b))

#print avg_diff[0].shape


plt.plot(avg_diff,label='greedy')
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3,
           ncol=2, mode="expand", borderaxespad=0.)

plt.show()
fig2.savefig('../Result/greedyz_randomz_approxerror.png')

"""
fnames = glob('../Result/randomq_valueaftereachstep*.txt')
arrays = [np.loadtxt(f) for f in fnames]
print len(arrays)
for i in range(len(arrays)):
	arrays[i][arrays[i] == float("inf")] = 0

b=np.loadtxt("../Result/v_iteration.txt");
b= b.ravel();
b[b == float("inf")] = 0
final_diff = []
num_states = np.shape(arrays[0])[1]
num_steps = np.shape(arrays[0])[0]
print num_states,num_steps
avg_diff = []
for i in np.arange(0, num_steps):
	diff_list_eachiteration = []
	for j in range(len(arrays)):
		diff_list = []
		for counter2 in np.arange(0, num_states):
			diff = abs(arrays[j][i][counter2] - b[counter2])
			diff_list.append(diff)
		
        diff_list_eachiteration.append(diff_list)
	#print diff_list_eachiteration
	avg_diff.append(np.mean(diff_list, axis= 0)/max(b))

#print avg_diff[0].shape


plt.plot(avg_diff,label='randomq')



for counter in np.arange(0, num_steps):
    	diff_list = []
    	for counter2 in np.arange(0, num_states):
        
        	diff = abs(a[counter][counter2] - b[counter2])

        	diff_list.append(diff)

num_states= np.shape(arrays[0])
num_steps= np.shape(arrays[0][1])
print num_states,num_steps
#for counter in np.arange(0,arrays[0]):


for n in range(10):

	a[n]=np.loadtxt("../Result/randomz_valueaftereachstep"+str(n)+".txt");
a[a == float("inf")] = 0

b[b == float("inf")] = 0
#print a[1]
print a[0][0][0];

num_states = np.shape(a)[1]


num_steps = np.shape(a)[0]
print num_steps
max_diff= [] 
for counter in np.arange(0, num_steps):
    diff_list = []
    for counter2 in np.arange(0, num_states):
        
        diff = abs(a[counter][counter2] - b[counter2])
        diff_list.append(diff)
    


    k = np.argmax(diff_list);
    max_diff.append(max(diff_list)/b[k])

fig2 = plt.figure()
plt.plot(max_diff,label='Greedy')"""
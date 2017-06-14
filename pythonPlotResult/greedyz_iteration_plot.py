import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
def z_iter_heatmap():
    a=np.loadtxt("../Result/randomz_iteration.txt");
    print a;
    fig=plt.figure()
    plt.imshow(a, cmap='hot', interpolation = 'nearest')
 #   plt.show()
    fig.savefig('../Result/randomz_iter_heatmap.png')

    a=np.loadtxt("../Result/greedyz_iteration.txt");
    print a;
    fig1=plt.figure()
    plt.imshow(a, cmap='hot', interpolation = 'nearest')
 #   plt.show()
    fig1.savefig('../Result/greedyz_iter_heatmap.png')

z_iter_heatmap()
a=np.loadtxt("../Result/greedyz_iteration_zvalue.txt");

a[a == float("inf")] = 0
b=np.loadtxt("../Result/z_iteration.txt");
b= b.ravel();

b[b == float("inf")] = 0
#print a[1]
num_states = np.shape(a)[1]
num_episodes = np.shape(a)[0]
max_diff= [] 
for counter in np.arange(0, num_episodes):
    diff_list = []
    for counter2 in np.arange(0, num_states):
        
        diff = abs(a[counter][counter2] - b[counter2])
        diff_list.append(diff)
    max_diff.append(max(diff_list)/max(a[counter]))
print (max_diff)
fig2 = plt.figure()
plt.plot(max_diff,label='Greedy')
#makeplt.show()
#fig2.savefig('../Result/greedyz_randomz_approxerror.png')



c=np.loadtxt("../Result/randomz_iteration_zvalue.txt");

c[c == float("inf")] = 0
num_states = np.shape(c)[1]
num_episodes = np.shape(c)[0]
max_diff= [] 
for counter in np.arange(0, num_episodes):
    diff_list = []
    for counter2 in np.arange(0, num_states):
        
        diff = abs(c[counter][counter2] - b[counter2])
        diff_list.append(diff)
    max_diff.append(max(diff_list)/max(a[counter]))
print (max_diff)
plt.plot(max_diff, label='Random')
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3,
           ncol=2, mode="expand", borderaxespad=0.)
plt.show()
fig2.savefig('../Result/greedyz_randomz_approxerror.png')

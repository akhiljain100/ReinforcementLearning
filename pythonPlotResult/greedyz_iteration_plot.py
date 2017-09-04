import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
'''def z_iter_heatmap():
    a=np.loadtxt("../Result/randomz_iteration.txt");
    fig=plt.figure()
    plt.imshow(a, cmap='hot', interpolation = 'nearest')
 #   plt.show()
    fig.savefig('../Result/randomz_iter_heatmap.png')

    a=np.loadtxt("../Result/greedyz_iteration.txt");
    fig1=plt.figure()
    plt.imshow(a, cmap='hot', interpolation = 'nearest')
 #   plt.show()
    fig1.savefig('../Result/greedyz_iter_heatmap.png')

z_iter_heatmap()'''

a=np.loadtxt("../Result/greedyz_zvalueaftereachsteps0.dat");

a[a == float("inf")] = 0
b=np.loadtxt("../Result/z_iteration.dat");
b= b.ravel();

b[b == float("inf")] = 0
#print a[1]
num_states = np.shape(a)[1]


num_episodes = np.shape(a)[0]
print num_episodes
max_diff= [] 
for counter in np.arange(0, num_episodes):
    diff_list = []
    for counter2 in np.arange(0, num_states):
        
        diff = abs(a[counter][counter2] - b[counter2])
        diff_list.append(diff)
    k = np.argmax(diff_list);
    max_diff.append(max(diff_list)/max(a[counter]))

fig2 = plt.figure()
plt.plot(max_diff,label='Greedy')
#makeplt.show()
#fig2.savefig('../Result/greedyz_randomz_approxerror.png')

'''

c=np.loadtxt("../Result/randomz_valueaftereachstep0.txt");

c[c == float("inf")] = 0
num_states = np.shape(c)[1]
num_episodes = np.shape(c)[0]
print num_episodes
max_diff= [] 
for counter in np.arange(0, num_episodes):
    diff_list = []
    for counter2 in np.arange(0, num_states):
        
        diff = abs(b[counter2]-c[counter][counter2])
        diff_list.append(diff)

    k = np.argmax(diff_list);
    max_diff.append(max(diff_list)/b[k])

plt.plot(max_diff, label='Random')



d=np.loadtxt("../Result/randomq_valueaftereachstep0.txt");

d[d == float("inf")] = 0
e=np.loadtxt("../Result/v_iteration.txt");
e= e.ravel();
e[e == float("inf")] = 0

num_states = np.shape(d)[1]
num_episodes = np.shape(d)[0]
max_diff= [] 
for counter in np.arange(0, num_episodes):
    diff_list = []
    for counter2 in np.arange(0, num_states):
        
        diff = abs(d[counter][counter2] - e[counter2])
        diff_list.append(diff)
    k=np.argmax(diff_list);
    max_diff.append(max(diff_list)/e[k])

plt.plot(max_diff, label='Random Q')
'''
plt.show()
fig2.savefig('../Result/greedyz_randomz_randomq_approxerror.png')

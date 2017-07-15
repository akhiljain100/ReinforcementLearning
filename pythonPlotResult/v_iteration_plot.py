import numpy as np
import matplotlib.pyplot as plt

def v_iter_heatmap():
    a=np.loadtxt("../Result/v_iteration.txt");
    print a;
    fig=plt.figure()
    plt.imshow(a, cmap='hot', interpolation = 'nearest')
 #   plt.show()
    fig.savefig('../Result/v_iter_heatmap.png')

 

v_iter_heatmap()

a=np.loadtxt("../Result/randomq_valueaftereachstep0.txt");

a[a == float("inf")] = 0
b=np.loadtxt("../Result/v_iteration.txt");
b= b.ravel();
b[b == float("inf")] = 0
print a[1]
num_states = np.shape(a)[1]
num_episodes = np.shape(a)[0]
max_diff= [] 
for counter in np.arange(0, num_episodes):
    diff_list = []
    for counter2 in np.arange(0, num_states):
        
        diff = abs(a[counter][counter2] - b[counter2])
        diff_list.append(diff)
    k=np.argmax(diff_list);
    max_diff.append(max(diff_list)/b[k])
print (max_diff)
fig2 = plt.figure()
plt.plot(max_diff)
plt.show()
fig2.savefig('../Result/randomq_iter_approxerror.png')

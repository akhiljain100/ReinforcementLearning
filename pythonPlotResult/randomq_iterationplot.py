import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
a=np.loadtxt("../Result/randomq_episodeiteration.txt");

a[a == float("inf")] = 0
b=np.loadtxt("../Result/v_iteration.txt");
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
    max_diff.append(max(diff_list)/b[k])

fig2 = plt.figure()
plt.plot(max_diff,label='Q Random')
plt.show()
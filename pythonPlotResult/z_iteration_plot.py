import numpy as np
import matplotlib.pyplot as plt
def z_iter_heatmap():
    a=np.loadtxt("../Result/z_iteration.dat");
    print a;
    a[a == float("inf")] = 0
    fig=plt.figure()
    plt.tick_params(
    axis='x',          # changes apply to the x-axis
    which='both',      # both major and minor ticks are affected
    bottom='off',      # ticks along the bottom edge are off
    top='off',         # ticks along the top edge are off
    labelbottom='off')
    plt.tick_params(
    axis='y',          # changes apply to the x-axis
    which='both',      # both major and minor ticks are affected
    left='off',      # ticks along the bottom edge are off
    right='off',         # ticks along the top edge are off
    labelleft='off')
    plt.imshow(a, cmap='hot', interpolation = 'nearest')
 #   plt.show()
    fig.savefig('../Result/v_iter_heatmap.png')
'''
    a=np.loadtxt("../Result/randomz_iteration.txt");
    print a;
    fig1=plt.figure()
    plt.imshow(a, cmap='hot', interpolation = 'nearest')
 #   plt.show()
    fig1.savefig('../Result/randomz_iter_heatmap.png')'''

z_iter_heatmap()
'''
a=np.loadtxt("../Result/randomz_iteration_zvalue.txt");

a[a == float("inf")] = 0
b=np.loadtxt("../Result/z_iteration.txt");
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
    max_diff.append(max(diff_list)/max(a[counter]))
print (max_diff)
fig2 = plt.figure()
plt.plot(max_diff)
plt.show()
fig2.savefig('../Result/randomz_iter_approxerror.png')
'''

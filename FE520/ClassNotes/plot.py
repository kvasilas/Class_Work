import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np

#Line Plots
def line():
    y = np.random.randn(20)
    #plt.plot(y) #plots a random 20 numbers
    """
    #same with or without defining x axis here
    x = range(len(y))
    plt.plot(x,y)
    """

    #cumulative example [4, 6, 12] -> [4, 4+6, 4+6+12] = [4, 10, 22]
    ycum = np.cumsum(y) #ycum is as above for random numbers
    plt.plot(ycum, 'y--', label = 'ycum') #y is color, -- is line style

    plt.grid(True) #grid on
    plt.xlim(-1,20) #limits are [-1, 20]
    #plt.ylim(ymin, ymax) #limits are [ymin, ymax]
    plt.xlabel('index')
    plt.ylabel('value')
    plt.title('Sample Plot!!!!')
    plt.plot(y, 'b.-', label = 'y', drawstyle = 'steps-post') #step graph
    plt.legend()
    return(plt.show())
#sub Plots
def subs():
    y = np.random.randn(20)
    ycum = np.cumsum(y)
    ax1 = plt.subplot(2, 2, 1)
    ax2 = plt.subplot(2, 2, 2)
    ax3 = plt.subplot(2, 2, 3)
    plt.plot(ycum)
    ax2.plot(y)
    return(plt.show())
#Cosine with ticks
def cos():
    fig, ax = plt.subplots(1,1)
    t =np.arange(0.0,5.0,0.01)
    s = np.cos(2*np.pi*t)
    plt.plot(t, s, lw = 2)
    ax.annotate('local min', xy=(1.5,-1), xytext=(2.5,-1.5), arrowprops=dict(facecolor='red',shrink=.075))
    plt.xticks([0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4], ['0', 'pi/2', 'pi', '3pi/2', '2pi', '5pi/2', '3pi', '7pi/2', '4pi'], rotation = 30, fontsize = 'medium')
    plt.ylim(-2,2)
    plt.xlim(-0.05,4.05)
    return(plt.show())
#3D Graphs
def threeD():
    strike = np.linspace(50,150,24)
    ttm = np.linspace(.5,2.5,24)
    strike2, ttm2 = np.meshgrid(strike, ttm)
    iv = ((strike2 - 100)**2/(100*strike2))/ ttm2
    #print(strike2[:2])

    from mpl_toolkits.mplot3d import Axes3D
    fig = plt.figure(figsize = (9,6))
    ax = fig.add_subplot(111, projection = '3d')
    surf = ax.plot_surface(strike2, ttm2, iv, cmap = plt.cm.coolwarm, rstride = 2, cstride = 2, linewidth = 0.5, antialiased = True)

    ax.set_xlabel('strike')
    ax.set_ylabel('time to maturity')
    ax.set_zlabel('implied volatility')

    fig.colorbar(surf, shrink = .6, aspect = 6)
    return(plt.show())
# Bar Graphs
def bars():
    fig, axes = plt.subplots(2,1)
    axes[0].bar(list('abcdefghijklmnop'), np.random.rand(16), color = 'b')
    axes[1].barh(list('abcdefghijklmnop'), np.random.rand(16), color = 'g')
    return(plt.show())
#scatter plot
def scatter():
    z = np.random.randn(100,2)
    c = np.random.randint(0,10,len(z))
    plt.figure(figsize = (7,4))
    plt.scatter(z[:,0], z[:,1], marker='o', c = c)
    #plt.scatter(z[:,0], z[:,1], marker='*', color = 'r') #marker can be o or *
    plt.grid(True)
    plt.title('Scatter Plot')
    return(plt.show())
#histograms
def hists():
    z = np.random.randn(100,3) #change second number for different inputs
    #plt.hist(z, label = ['uno', 'dos', 'tres'], bins = 10) #bins is number of pairs
    plt.hist(z, label = ['uno', 'dos', 'tres'], bins = 15, color = ['b', 'r', 'y'], stacked = True)
    plt.grid(True)
    plt.title('Histogrammy')
    return(plt.show())
#box plots
def Box():
    z = np.random.randn(100,3) #change second number for different inputs
    plt.boxplot(z)
    plt.grid(True)
    plt.title('Box Plot')
    plt.xticks([1,2,3], ['uno', 'dos', 'tres'], fontsize = 'large')
    return(plt.show())
#other plots with weird names
def seaborn():
    import seaborn as sbn
    xaxis = np.linspace(-3, 3, 100)
    yaxis = xaxis + np.random.randn(100)
    sbn.regplot(xaxis, yaxis, color = 'r')
    return(plt.show())
def Bokeh():
    import bokeh.plotting as bp
    import datetime
    values = np.cumsum(np.random.randn(1000))
    dates = [datetime.date.today() + datetime.timedelta(days = x) for x in range(len(values))]
    handle = bp.figure(
        plot_width=800,
        plot_height=800,
        title = 'Historical Stock Quotes',
        x_axis_type = 'datetime',
        tools = 'pan, wheel_zoom, box_zoom'
    )

    handle.line(dates, values, line_width=2)

    return(bp.show(handle))
def choose():
    print('Enter the number you wish to display:', '1) Line Plots', '2) Sub Plots', '3) Cosine', '4) 3d', '5) Bar', '6) Scatter Plots', '7) Histograms', '8) Box', '9) Seaborn', '10) Bokeh', 'Anything else to leave', ':', sep='\n' )
    x = int(input())
    print(x)
    if(x == 1):
        line()
        choose()
    elif(x==2):
        subs()
        choose()
    elif(x==3):
        cos()
        choose()
    elif(x==4):
        threeD()
        choose()
    elif(x==5):
        bars()
        choose()
    elif(x==6):
        scatter()
        choose()
    elif(x==7):
        hists()
        choose()
    elif(x==8):
        box()
        choose()
    elif(x==9):
        seaborn()
        choose()
    elif(x==10):
        Bokeh()
        choose()
    else:
        print('BYE')
choose()

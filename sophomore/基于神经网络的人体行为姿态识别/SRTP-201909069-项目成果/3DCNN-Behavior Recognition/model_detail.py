import h5py

#打开文件
f1 = h5py.File('.\\data\\checkpoint\\inception.001-2.03.hdf5','r')
f2 = h5py.File('.\\data\\checkpoint\\inception.002-1.77.hdf5','r')
f3 = h5py.File('.\\data\\checkpoint\\inception.005-1.64.hdf5','r')
f4 = h5py.File('.\\data\\checkpoint\\inception.015-1.58.hdf5','r')
f5 = h5py.File('.\\data\\checkpoint\\inception.016-1.55.hdf5','r')
f6 = h5py.File('.\\data\\checkpoint\\inception.022-1.39.hdf5','r')
f7 = h5py.File('.\\data\\checkpoint\\inception.029-1.39.hdf5','r')

with h5py.File('.\\data\\checkpoint\\inception.001-2.03.hdf5','r') as f:
    def prtname(name):
        print(name)
    f.visit(prtname)
    subgroup = f['subgroup']
    subsub = subgroup['subsub']
    data1 = subgroup['data1']
    data2 = subsub['data2']
    # print(dset)
    print("data1 name:",data1.name,"data2 name",data2.name)
    print("data1 shape:",data1.shape,"data2 shape:",data2.shape)
    print("data1 dtype:",data1.dtype,"data2 dtype:",data2.dtype)
    print("data1:",data1[:],"data2:",data2[:])
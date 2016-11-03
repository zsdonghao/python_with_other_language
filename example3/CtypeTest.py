# -*- coding: utf-8 -*-
from ctypes import *


class DataStruct(Structure):
    _fields_ =[('id',c_int),
               ('name',c_char_p),
               ('purl',c_char_p),
               ('pridata',c_void_p)]
    
    def __str__(self):
        return 'id:{0} name:{1}'.format(self.id, self.name);
    
class PyDataStruct(object):
    def __init__(self):
        try:
            self.swigdll = CDLL("./CtypeTest.so")
            self.swigdll.DataStruct_Create.restype = POINTER(DataStruct)
            self.datastruct = self.swigdll.DataStruct_Create()
        except Exception as e:
            self.swigdll = None
            self.datastruct = None
    
    def __del__(self):
        if(self.swigdll is not None):
            pass
#             self.swigdll.DataStruct_Destroy(byref(self.datastruct))
            
    def getName(self):
        return self.datastruct.contents.name;
    
    def setName(self, name):
        self.datastruct.contents.name = name
        
    def getUrl(self):
        return self.datastruct.contents.purl;
    
    def setUrl(self, url):
        self.datastruct.contents.purl = url
        
    def getNameByc(self):
        self.swigdll.DataStruct_GetName.restype = c_char_p
        return self.swigdll.DataStruct_GetName(self.datastruct)
    
    def setNameByc(self, name):
        return self.swigdll.DataStruct_SetName(self.datastruct, name)

    
    
def DataStruct_test():
    sdata = PyDataStruct()
    sdata.setName("pg".encode("utf-8"))
    print("name=%s"%sdata.getName())
    sdata.setUrl("http://pg.com".encode("utf-8"))
    print("url=%s"%sdata.getUrl())
    
    sdata.setNameByc("ctest")
    print("name=%s"%sdata.getNameByc())



def func_test():
    swigtest = CDLL("./CtypeTest.so")
    # sub_test
#     swigtest.sub_test.argtypes=[c_int, c_int]
    print("--------------sub_test test---------------------")
    print("sub=%d"%swigtest.sub_test(20, 1))
    
    # add2_test
#     swigtest.add2_test.argtypes=[c_int, c_void_p]
    print("--------------add2_test test---------------------")
    d2=c_int(7)
    print("add2_test=%d"%swigtest.add2_test(2, byref(d2)))
    
    #add_test
    print("--------------add_test test---------------------")
    d3=c_int(-1)
    print(d3.value)
    print("add_test=%d"%swigtest.add_test(2, 32, byref(d3)))
    print(d3.value)
    
    #sum2_test
    print("--------------sum2_test test---------------------")
    d4=c_int(14)
    print("sum2_test=%d"%swigtest.sum2_test(2, byref(d4)))
    
    #sum3_test
    print("--------------sum3_test test---------------------")
    d5=c_int(14)
    d6=c_int(7)
    print("sum3_test=%d"%swigtest.sum3_test(2, byref(d6), byref(d5)))
    
    #char1_test
    print("--------------char1_test test---------------------")
    str1 = create_string_buffer(32)
    print("sum3_test=%d"%swigtest.char1_test(str1, -1))
    print(str1.value)
    
    #char1_test
    print("--------------char2_test test---------------------")
    app_id = "123456"
    asr_path = "haha"
    print(swigtest.char2_test(app_id.encode("utf-8"), asr_path.encode("utf-8")))



if __name__ == "__main__":
    #func test
    func_test()

    #datastruct test
    DataStruct_test()

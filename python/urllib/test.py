class Foo:
    def __init__(self, inp):
        self.__dict__.update({"a":1, "b":2})


#        allowed_keys = ['a', 'b', 'c']
#        self.__dict__.update((k, v) for k, v in kwargs.iteritems() if k in allowed_keys)

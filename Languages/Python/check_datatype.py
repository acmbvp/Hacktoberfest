class Variable:

    def __init__( self, variable): # Constructor is created
       self.variable = variable # Variable is initialised

    def Type_Variable( self ):
        typevariable = type(self.variable) #Type is used to find the datatype
        print( " The type of Datatype is {} ".format(typevariable))

# Creating different objects
# Calling the function
V1 = Variable(2)
V2 = Variable("ACMBVP")
V3 = Variable(2.0)
V1.Type_Variable()
V2.Type_Variable()
V3.Type_Variable()

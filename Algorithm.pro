TEMPLATE = subdirs

HEADERS += \
           include/LinearList.hpp \
           include/changeLength1D.hpp \
           include/ExtendedLinearList.hpp \

SUBDIRS += \
    Exception \
    ArrayList \
    ArrayListWithIterator \
    ArrayListNoSTL \
    VectorList \
    Chain \
    ChainWithIterator \
    # ExtendedChain \
    CircularListWithHeader \
    BinSort \
    BinSort2 \
    IrregualrArray \
    Matrix

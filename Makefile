CXX_FLAGS      := $(shell pkg-config --cflags protobuf) -xc++
LD_FLAGS       := $(shell pkg-config --libs protobuf)

PROTOS         := $(wildcard *.proto)
PROTO_OBJS     := $(PROTOS:.proto=.pb.o)

BINS     := GamePlanner

SRCS     := $(wildcard Backend/*.cu)
OBJS     := $(SRCS:.cu=.o)
DEPS     := $(SRCS:.cu=.d)

PBSRCS   := $(wildcard proto/*.proto)
PBOBJS   := $(PROTOS:.proto=.pb.o)
PBGENS   := $(PROTOS:.proto=.pb.cc) $(PROTOS:.proto=.pb.h)

all: $(BINS)

clean:
        rm -f $(BINS) $(OBJS) $(DEPS) $(PBOBJS) $(PBGENS)

$(BINS): $(OBJS)
$(OBJS): $(DEPS)
$(DEPS): $(PBOBJS)

.PRECIOUS: $(PBGENS)

%.d: %.cu
        $(CXX) -M $(CXX_FLAGS) $< > $@

%.pb.cc: %.proto
        protoc --cpp_out=. $<

%.pb.o : %.pb.cc
        $(CXX) $(CXX_FLAGS) -c -o $@ $<

%.o: %.cu
        $(CXX) $(CXX_FLAGS) -c -o $@ $<

$(BINS): %: %.o
        $(CXX) $(LD_FLAGS) -o $@ $(PROTO_OBJS) $^

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif


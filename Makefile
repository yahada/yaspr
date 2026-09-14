
CXX := g++
CPPFLAGS := -MMD -MP
CXXFLAGS := -O2 -Wall -Wextra -std=c++17

OUT_O_DIR ?= build
CPPSRC =  yanet/linkLayer/protocols/ethernet.cpp yanet/linkLayer/linkLayerHeader.cpp yanet/networkLayer/protocols/IPv4.cpp yanet/packet.cpp main.cpp sniffer.cpp

CPPOBJ := $(CPPSRC:%.cpp=$(OUT_O_DIR)/%.o)
DEPS = $(CPPOBJ:.o=.d)

.PHONY: all
all: $(OUT_O_DIR)/yaspr

$(OUT_O_DIR)/yaspr: $(CPPOBJ)
	$(CXX) $^ $(LDFLAGS) -lpcap -o $@

$(OUT_O_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
-include $(DEPS)


run: $(OUT_O_DIR)/yaspr
	sudo ./$^
clean:
	rm -rf $(OUT_O_DIR)

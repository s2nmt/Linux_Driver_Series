# Device Tree
Device tree is a data structure and language for describing hardware. More specifically, it is a description of hardware that is readable by an opearating system so that the operating system doesn't need to hard code details of the machine.

Structurally, the DT is a tree, or acyclic graph with named nodes, and nodes may have an arbitrary number of named properties ancapsulating arbitrary data. A mechanism also exits to create arbitrary links from one node to another outside of the natural tree structure.

Concepturally, a common set of useage conventions, called 'bindings' is defined for how data should appear in the tree to describe typical hardware characteristics including data busses, interrupt lines, GPIO connections and peripheral devices.

As much as possible, hardware is described using existing binding to maximize use of existing support code, but since property and node names are simply text strings, it is easy to extend existing bindings or create new ones by defining now nodes and properties. 
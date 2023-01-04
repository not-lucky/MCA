# practical cheat sheet

Components req:

ICS, hookup wires, power supply

Theory:

- logic gate elementary building block.
- most have 2 in 1 out
- at any moment, every terminal is one of 2 binary condition, low (0) or high (1).

GATE_NAME GATE:

- following is true when both true.
- DIAGRAM AND TRUTH TABLE.

ADDITIONAL SHIT

AND: is so named cause if 0 is false and 1 is true, then behave 'LOGICAL' AND operator.
OR: 'LOGICAL INCLUSIVE' OR operator.
NOT: INVERTOR, 1 input, reverses logical state.
NAND: comb. AND and NOT (invertor).
NOR: same as above.
EXOR: 'LOGICAL' OR. explain some shit.

PRECAUTIONS:

- check output of all ICS.
- all connections proper and according to diag.
- handle kit carefully

IC DIAGRAM:
TABLE:
RESULT:

## FOR THESE

HALF ADDER:

- add 2 bin bits, op. called half add and half adder is used.
- Boolean Eq.
  - The output equations for half adder are:
    S = f(X,Y) = ∑( 1,2) = x’y + xy’
    Bout = f(X,Y) = ∑(3) = xy

HALF SUBTRACTOR:

- sub 2 bin bits.
- 2 inp (minuend, subtrahend), 2 out D and BORROW.
  - The output equations for half sub are:
    S = f(X,Y) = ∑( 1,2) = x’y + xy’
    Bout = f(X,Y) = ∑(1) = x'y

FULL ADDER:

- comb., add 3 bits.
- 3 in, 2 out Sum and C
- The Boolean equations for the full adder are:
  S = f(X,Y,Cin) =∑(1,2,4,7)
  Bout = f(X,Y,Cin) = ∑(3,5,6,7)
  
  The final equations are:
  S = X’Y’Cin + X’YCin’ + XY’Cin’+ XYCin
  Cout = XY + XCin + YCin

FULL SUBTRACTOR:

- The Boolean equations for the full subtractor are
  D = f(X,Y,Bin) = ∑(1,2,4,7)
  Bout = f(X,Y,Bin) = ∑(1,2,3,7)
  
  The final equations are
  D = X’Y’Bin + X’YBin + XY’Bin’+ XYBin
  Bout = X’Y + X’Bin + YBin

PROCEDURE:

1. see data sheet of IC .....
2. place IC on breadboard.
3. Connect Vcc to pin 14 ....
4. make conn. as shown in fig.
5. power supply
6. observe and match truth table.

# FLIP FLOPS

THEORY:

- simplest is sequential cir. with 2 states.
- its a mem cell, sotre 1 bit.
- also know as latch
- synchonous cir change state only when clock
- modified _ extra control input to latch to change state.
- this is called flip flop.
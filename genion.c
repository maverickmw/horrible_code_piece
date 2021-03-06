/* in gmx_genion.c 
https://github.com/maverickmw/gromacs/blob/master/src/gromacs/gmxana/gmx_genion.c

line: 423 - 428
purpose to compute total charge of a structure.

*/

real qtot = 0;

for (i = 0; (i < atoms.nr); i++)
    {
        qtot += atoms.atom[i].q;
    }
    
iqtot = gmx_nint(qtot);

/* for float point precision, the for loop result will not reliable with atoms.nr > 100,000. 
Tiny mistake will lead to none neutral system.


Possible fix:
Sum qtot according to atom type.
atom types are limited.
*/

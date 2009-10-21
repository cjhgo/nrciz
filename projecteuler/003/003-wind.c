/*
 *
 *  Portions Copyright (C) 2009 wind (xihels@gmail.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
   printf("求600851475143的最大质因数 --wind\n");
   long long sum = 600851475143;
   sum  = (long long)sqrt(sum);
   int succeed;
   long long i;
   long long max;
   if (0 == sum % 2)
	   sum++;
   for (; sum > 2; sum -= 2) {
	   succeed = 1;
	   max = (long long)sqrt(sum);
	   if (0 ==  max % 2)
		   max++;
	   for (i = 3; i < max; i += 2) {
		   if (0 == sum % i) {
			   succeed = 0;
			   break;
		   }
	   }
	   if (succeed) {
		   printf("result = %lld\n", sum);
		   break;
	   }

   }
   return 0;
}


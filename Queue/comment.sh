/***************************************************************
 * File   : comment.sh
 * Author : Babribhan Jangra <babribhan@gmail.com>
 * Date   : July 01 ,2017 TIME :12:11:09
 ***************************************************************/
#!/bin/ksh
for file in `ls *.*`
do
  echo "/***************************************************************">>temp_file
  echo " * File   : $file">>temp_file
  echo " * Author : Babribhan Jangra <babribhan@gmail.com>">>temp_file
  echo " * Date   : `date '+%B %d ,%Y TIME :%H:%S:%M'`">>temp_file
  echo " ***************************************************************/">>temp_file
  cat $file>>temp_file
  mv -f temp_file $file
done
exit 0

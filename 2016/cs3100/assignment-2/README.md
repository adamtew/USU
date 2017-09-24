# Threaded Mandelbrot

> Extend your first Mandelbrot program to use multiple threads to speed up computation.  Use at least two different strategies for dividing the work.

> Include a short (2-3 paragraph) written report about your findings.  The report must include a description of your strategies for dividing work and your hypothesis for which will be superior and why.  The report must also include your results and speed up calculations for both of your strategies.

> Testing the difference in processing times for the creation of a threaded mandelbrot against that of a serial mandelbrot

## Method 1

> Create a thread for groups of rows. Where a group = total rows / number of threads

### Macbook Pro

|Threads|1|2|3|4|5|10|15|20
|---|---|---|---|---|---|---|---|---|
||974|469|556|366|368|201|172|154|
||945|458|554|368|379|209|164|148|
||924|456|551|363|377|211|164|151|
||911|455|558|364|375|243|160|146|
||912|450|566|361|380|204|163|155|
||918|456|563|364|376|211|164|152|
||916|453|561|367|372|207|160|156|
||914|452|581|364|369|200|166|159|
||925|455|596|363|365|204|164|150|
||930|457|561|365|361|199|167|148|
|Average|__926__|__456__|__564__|__364__|__372__|__208__|__164__|__151__|
|Standard Deviation|__18__|__4__|__13__|__1__|__5__|__12__|__3__|__3__|

### Raspberry Pi

|Threads|1|2|3|4|5|10|15|20|
|---|---|---|---|---|---|---|---|---|
||3899|2009|2368|1598|1567|1065|1028|1035|
||3899|1973|2325|1627|1634|1123|1085|1045|
||3898|1970|2336|1627|1609|1190|1096|1017|
||3898|1976|2365|1598|1590|1127|1025|1056|
||3896|1971|2376|1616|1599|1143|1091|1059|
||3916|1978|2323|1626|1633|1194|1036|1047|
||3916|1969|2345|1617|1568|1202|1045|1051|
||3917|2013|2347|1601|1551|1176|1061|1007|
||3919|1993|2321|1626|1574|1102|1055|1036|
||3915|1973|2325|1623|1593|1131|1037|1025|
|Average|__3907__|__1982__|__2343__|__1615__|__1591__|__1145__|__1055__|__1037__|
|Standard Deviation|__9__|__15__|__19__|__11__|__26__|__42__|__25__|__16__|

## Method 2

> Method 2 is very similar to method 1 just flipping rows to columns.

|Threads|1|2|3|4|5|10|15|20|
|---|---|---|---|---|---|---|---|---|
||930|680|407|408|357|228|186|169|
||934|648|406|413|346|197|179|162|
||952|662|406|400|347|197|175|156|
||952|652|412|400|345|201|170|161|
||943|652|404|395|347|206|176|154|
||927|663|402|398|342|199|180|160|
||950|664|398|410|347|197|184|156|
||921|647|403|408|347|194|174|162|
||942|663|410|415|339|201|174|155|
||994|656|399|430|336|196|177|157|
|Average|__944__|__658__|__404__|__407__|__345__|__201__|__177__|__159__|
|Standard Deviation|__19__|__9__|__4__|__9__|__5__|__9__|__4__|__4__|

### Raspberry Pi

|Threads|1|2|3|4|5|10|15|20|
|---|---|---|---|---|---|---|---|---|
||3913|2761|1739|1708|1580|1111|1058|1038|
||3915|2748|1749|1745|1563|1146|1085|1033|
||3914|2791|1775|1718|1542|1105|1049|1077|
||3915|2762|1779|1745|1450|1117|1121|1055|
||3905|2789|1765|1765|1471|1081|1114|1048|
||3913|2761|1769|1769|1523|1102|1158|1020|
||3911|2772|1740|1762|1489|1068|1083|1057|
||3910|2785|1754|1762|1473|1085|1060|1079|
||3912|2769|1755|1749|1446|1073|1101|1081|
||3905|2773|1744|1745|1519|1197|1132|1037|
|Average|__3911__|__2771__|__1756__|__1746__|__1505__|__1108__|__1096__|__1052__|
|Standard Deviation|__3__|__13__|__13__|__19__|__44__|__36__|__33__|__20__|

## Conclusion

After looking over the results of both methods, it's pretty clear to see that they're almost identical. It's also interesting to see how the number of threads play a role. On the macbook, it would appear that it keeps on improving until about 20 threads, which is where it starts to level out.

|Speed Up|Macbook Pro|Pi|
|---|---|---|
|Method I|6.1|3.7|
|Method II|5.9|3.7|
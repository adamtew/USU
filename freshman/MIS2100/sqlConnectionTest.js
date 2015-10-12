var connection = new ActiveXObject("ADODB.connection") ;

var connectionString = "UserID=;Password=;" ;

connection.Open(connectionString);
var rs = new ActiveXObject("ADODB.Recordset");

rs.Open("Select * From table", connection);
rs.MoveFirst
while(!rs.eof)
{

	document.write(rs.fields(1));
	rs.movenext;
}

rs.Close;
connection.close;

var OctoCat = true;
<!DOCTYPE html>
<!-- Team.php
	Database portion of program.
     -->
<html lang = "en">
  <head>
    <title>HW6</title>
    <meta charset = "utf-8" />
	<link rel = "stylesheet" type = "text/css" href = "stylesheet.css" />
  </head>
  
  <body>
<?php
//connect to server
$servername = "localhost";
$username = "leack001";
$password = "leack001";
$dbname = "leack001";
$conn = new mysqli($servername, $username, $password, $dbname);

//show error if connection failed
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
//get user value
$userValue = $_POST['userValue'];

//perform SQL query
$sql = "SELECT teamID, teamName, startYear, ownerName, GMName, coachName, startQB, officeAddress, city, state, zipcode, phone, overallRecord, confRecord FROM Teams WHERE teamID=$userValue";
$result = $conn->query($sql);

//show results
if ($result->num_rows > 0) {
	echo "<table border='1'>
	<tr>
	<th>Team ID</th>
	<th>Team Name</th>
	<th>Start Year</th>
	<th>Owner Name</th>
	<th>GM Name</th>
	<th>Coach Name</th>
	<th>Starting QB</th>
	<th>Office Address</th>
	<th>City</th>
	<th>State</th>
	<th>Zip Code</th>
	<th>Phone</th>
	<th>Overall Record</th>
	<th>Conference Record</th>
	</tr>";

	while($row = mysqli_fetch_array($result))
		{
			echo "<h2>This is the team you were looking for:";
			echo "<tr>";
			echo "<td>" . $row['teamID'] . "</td>";
			echo "<td>" . $row['teamName'] . "</td>";
			echo "<td>" . $row['startYear'] . "</td>";
			echo "<td>" . $row['ownerName'] . "</td>";
			echo "<td>" . $row['GMName'] . "</td>";
			echo "<td>" . $row['coachName'] . "</td>";
			echo "<td>" . $row['startQB'] . "</td>";
			echo "<td>" . $row['officeAddress'] . "</td>";
			echo "<td>" . $row['city'] . "</td>";
			echo "<td>" . $row['state'] . "</td>";
			echo "<td>" . $row['zipcode'] . "</td>";
			echo "<td>" . $row['phone'] . "</td>";
			echo "<td>" . $row['overallRecord'] . "</td>";
			echo "<td>" . $row['confRecord'] . "</td>";
			echo "</tr>";
		}
	echo "</table>";
    }
else {
	die("ERROR: Team ID is invalid. Please go back and try again.");
	}
?>
  </body>
</html>
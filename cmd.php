<?php
$conn = new mysqli("localhost", "root", "", "app");
// SQL injection
$res = $conn->query("SELECT * FROM users WHERE name = '" . $_GET['name'] . "'");

// Command injection
system("ping -c 1 " . $_GET['host']);

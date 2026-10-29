import java.sql.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Connection c = DriverManager.getConnection("jdbc:sqlite:app.db");
        Statement s = c.createStatement();
        // SQL injection
        ResultSet r = s.executeQuery("SELECT * FROM users WHERE name = '" + args[0] + "'");
        while (r.next()) System.out.println(r.getString(1));
    }
}

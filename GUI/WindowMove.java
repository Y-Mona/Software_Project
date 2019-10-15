import java.awt.*;
import javax.swing.*;

import org.graalvm.compiler.core.common.type.ArithmeticOpTable.BinaryOp.Add;

public class WindowMove extends JFrame{
	LP LayeredPane;
	public WindowMove() {
		// TODO Auto-generated constructor stub
		LayeredPane = new LP();
		add(LayeredPane,BorderLayout.CENTER);
		setVisible(true);
		setBounds(12,12,300,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}

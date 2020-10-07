#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64  # Change 'example_interfaces'


class PubNode(Node):  # Change 'PubNode'

    def __init__(self):
        super().__init__("pub_node")  # Change 'pub_node'

        self.number_ = 2
        self.numberPublisher_ = self.create_publisher(
            Int64, "/data/number", 10)
        self.numberTimer_ = self.create_timer(1.0, self.publishNumber)

        self.get_logger().info("Pub node has been started.")  # Change 'Pub node'

    def publishNumber(self):
        msg = Int64()
        msg.data = self.number_
        self.numberPublisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = PubNode()    # Change 'PubNode'
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()

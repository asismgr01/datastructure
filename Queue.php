<?php 
 class Queue{
    protected $front = -1;
    protected $rear = -1;
    protected $array = null;
    public function __construct($value){
        $this->array = new SplFixedArray($value);
        echo "Array size is ".sizeof($this->array);
    }
    public function isEmpty(){
       if ($this->rear == -1) {
       	 return true;
       }
       else{
       	return false;
       }
    }
    public function isFull(){
       if($this->rear == sizeof($this->array)-1){
       	return true;
       }
       else{
       	return false;
       }
    }
    public function inqueue($value){
       if ($this->isFull()) {
       	  echo "Queue is full.";
       }
       else if($this->isEmpty()){
          $this->rear += 1;
          $this->front = $this->rear;
          $this->array[$this->rear] = $value;
          echo($value." successfully added");
       }
       else{
          $this->rear += 1;
          $this->array[$this->rear] = $value;
          echo($value." successfully added");
       }
    }
    public function dequeue(){
        if ($this->isEmpty()) {
        	echo("Queue is empty");
        }
        else{
        	$num = $this->array[$this->front];
        	$this->front += 1;
        	if ($this->front > sizeof($this->array)-1 ) {
        		$this->front = -1;
        		$this->rear = -1;
        	}
            echo($num." successfully dequeued.");
        }
    }
    public function front(){
        echo "Front index is ".$this->front;
    }
    public function rear(){
    	echo "Rear index is ".$this->rear;
    }
    public function traverse(){
       if ($this->isEmpty()) {
       	  echo("Queue is empty");
       }
       else{
       	  $array = array();
       	  for ($i = $this->front; $i <= $this->rear ; $i++) { 
       	  	  $array[$i] = $this->array[$i];
       	  }
       	  print_r($array);
       }
    }
 };
 $obj = new Queue(5);
 $obj->inqueue(1);
 $obj->inqueue(2);
 $obj->inqueue(3);
 $obj->inqueue(4);
 $obj->front();
 $obj->dequeue();
 $obj->front();
 $obj->traverse();
 $obj->dequeue();
 $obj->traverse();
 $obj->inqueue(5);
 $obj->traverse();
 $obj->inqueue(6);
 $obj->dequeue();
 $obj->dequeue();
 $obj->dequeue();
 $obj->front();
 $obj->rear();
 $obj->traverse();
 ?>
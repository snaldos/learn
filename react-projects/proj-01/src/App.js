import "./App.css";
import Accordian from "./components/accordian";
import RandomColor from "./components/random-color";
import StarRating from "./components/star-rating";
import ImageSlider from "./components/image-slider";
import LoadMoreData from "./components/load-more-data";

function App() {
  return (
    <div className="App">
      {/* Accordian component */}
      {/* <Accordian /> */}

      {/* RandomColor component */}
      {/* <RandomColor /> */}

      {/* StarRating component */}
      {/* <StarRating noOfStars={10}/> */}

      {/* ImageSlider component */}
      {/* <ImageSlider url={"https://picsum.photos/v2/list/"} limit={"10"} page={"1"} /> */}

      {/* Load more products component */}
      <LoadMoreData/>

    </div>
  );
}

export default App;

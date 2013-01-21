$(document).ready(function(){
    options = {
        chart: {
            renderTo: 'container',
            defaultSeriesType: 'line'
        },
        title: {
            text:chartitle
        },
        subtitle: {
            text: ''
        },
        xAxis: xAxis,
        yAxis: yAxis,
        tooltip: {
            enabled: false,
            formatter: function() {
                return '<b>'+ this.series.name +'</b><br/>'+
                this.x +': '+ this.y +'°C';
            }
        },
        plotOptions: {
            line: {
                dataLabels: {
                    enabled: true
                }
            }
        },
        series:series
    };
    chart = new Highcharts.Chart(options);
});
